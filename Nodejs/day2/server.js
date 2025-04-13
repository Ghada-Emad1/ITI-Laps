const http = require("http");
const fs = require("fs");
const url = require("url");
const path = require("path");

// define the public directory
const PUBLIC_DIR = path.join(__dirname, "public");

function readNotes() {
  const dataString = fs.readFile("./notes.json", "utf-8");
  return JSON.parse(dataString);
}
function writeNotes(data) {
  return fs.writeFileSync("./notes.json", JSON.stringify(data, null, 2));
}
function serveStaticFiles(res, filePath, contentType) {
    fs.readFile(filePath, (err, data) => {
        if (err) {
            res.writeHead(404, { 'content-type': 'application/json' });
            res.end(JSON.stringify({ error: "Not found" }));
            return;
        }
        res.writeHead(200, { 'content-type': contentType});
        res.end(data);
    })
}

const server = http.createServer((req, res) => {
  const parsedUrl = url.parse(req.url, true);
  const pathname = parsedUrl.pathname;
    // console.log(`${req.method} ${pathname}`);
    
    //serve static files 
    if ( req.method==='GET'&&pathname === "/") {
        serveStaticFiles(res,path.join(PUBLIC_DIR, 'index.html'), 'text/html');
        return;
    }
if (pathname.startsWith('/public/')) {
    const filePath = path.join(PUBLIC_DIR, pathname.replace('/public/', ''));
    console.log(`Serving static file: ${filePath}`); // Debug log
    const extname = path.extname(filePath);
    const contentTypes = {
        '.html': 'text/html',
        '.css': 'text/css',
        '.js': 'text/javascript'
    };
    const contentType = contentTypes[extname] || 'text/plain';
    serveStaticFiles(res, filePath, contentType);
    return;
}

    // get all notes
  if (req.method === "GET" && pathname == "/api/notes") {
    const notes = readNotes();
    res.writeHead(200, { "content-type": "application/json" });
    res.end(JSON.stringify(notes));
    return;
  }
    // get method based on specific id
  if (req.method == "GET" && pathname.startsWith("/api/notes/")) {
    const id = parseInt(pathname.split("/")[3]);
    const notes = readNotes();
    const note = notes.filter((note) => note.id === id);
    // console.log(note);
    if (note) {
      res.writeHead(200, { "content-type": "application/json" });
      res.end(JSON.stringify(note));
    } else {
      res.writeHead(404, { "content-type": "application/json" });
      res.end(JSON.stringify({ error: "Not Found" }));
    }
    return;
  }
    //post method
  if (req.method === "POST" && pathname === "/api/notes") {
    let body = "";
    req.on("data", (chunk) => {
      body += chunk.toString();
    });

    req.on("end", () => {
      const notes = readNotes();
      const newNoteData = JSON.parse(body);
      const newNote = {
        id: notes.length + 1,
        ...newNoteData,
      };
      notes.push(newNote);
      fs.writeFileSync("./notes.json", JSON.stringify(notes, null, 2));
      res.writeHead(201, { "content-type": "application/json" });
      res.end(JSON.stringify(newNote));
    });
  }
    
    // put method
    if (req.method === "PUT" && pathname.startsWith("/api/notes/")) {
        const id = parseInt(pathname.split('/')[3]);
        let body = '';
        req.on('data', (chunk) => {
            body += chunk.toString();
        })
        req.on('end', () => {
            const notes = readNotes();
            const updatedNote = JSON.parse(body);
            const index = notes.findIndex((note) => note.id === id);
            if (index!=-1) {
                notes[index] = { ...notes[index], ...updatedNote };
                writeNotes(notes);
                res.writeHead(200, { 'content-type': 'application/json' });
                res.end(JSON.stringify(notes[index]));
            } else {
                res.writeHead(404, { 'content-type': 'application/json' });
                res.end(JSON.stringify({error:"not found"}))
            }
        })
    }
    // delete method
    if (req.method === "DELETE" && pathname.startsWith('/api/notes/')) {
        const id = parseInt(pathname.split("/")[3]);
        const notes = readNotes();
        const index = notes.findIndex((note) => note.id === id);
        if (index != -1) {
            const deletedNote = notes.splice(index, 1)[0];
            writeNotes(notes);
            res.writeHead(200, { 'content-type': 'application/json' });
            res.end(JSON.stringify({message:"Note deleted ",note:deletedNote}))
        } else {
            res.writeHead(404, { 'content-type': 'application/json' });
            res.end(JSON.stringify({ error: "Note not Found" }));
        }
    }
});
const PORT = process.env.PORT || 3000;

server.listen(PORT, () => {
  console.log(`Server running at http/localhost:${PORT}`);
});
