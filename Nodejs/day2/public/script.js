const noteForm = document.getElementById('noteForm');
const notesList = document.getElementById('notesList');
const titleInput = document.getElementById('title');
const noteIdInput = document.getElementById('noteId');
const cancelBtn = document.getElementById('cancelBtn');

// Fetch all notes from the server
async function fetchNotes() {
    try {
        const response = await fetch("http://localhost:3000/api/notes");
      const notes = await response.json();
      console.log(notes);
        renderNotes(notes);
    } catch (error) {
        console.error('Error fetching notes:', error);
    }
}

// Render notes in the notes list
function renderNotes(notes) {
    notesList.innerHTML = ''; // Clear the list
    notes.forEach(note => {
        const noteDiv = document.createElement('div');
        noteDiv.classList.add('note');
        noteDiv.innerHTML = `
            <h3>${note.title}</h3>
            <button onclick="editNote(${note.id}, '${note.title}')">Edit</button>
            <button onclick="deleteNote(${note.id})">Delete</button>
        `;
        notesList.appendChild(noteDiv);
    });
}

// Add or update a note
noteForm.addEventListener('submit', async (e) => {
    e.preventDefault();
    const noteId = noteIdInput.value;
    const title = titleInput.value;

    if (noteId) {
        // Update an existing note
        try {
            const response = await fetch(`/api/notes/${noteId}`, {
                method: 'PUT',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ title })
            });
            if (response.ok) {
                fetchNotes();
                resetForm();
            }
        } catch (error) {
            console.error('Error updating note:', error);
        }
    } else {
        // Add a new note
        try {
            const response = await fetch('/api/notes', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ title })
            });
            if (response.ok) {
                fetchNotes();
                resetForm();
            }
        } catch (error) {
            console.error('Error adding note:', error);
        }
    }
});

// Edit a note
function editNote(id, title) {
    noteIdInput.value = id;
    titleInput.value = title;
    cancelBtn.style.display = 'inline-block';
}

// Delete a note
async function deleteNote(id) {
    try {
        const response = await fetch(`/api/notes/${id}`, {
            method: 'DELETE'
        });
        if (response.ok) {
            fetchNotes();
        }
    } catch (error) {
        console.error('Error deleting note:', error);
    }
}

// Reset the form
function resetForm() {
    noteIdInput.value = '';
    titleInput.value = '';
    cancelBtn.style.display = 'none';
}

// Cancel editing
cancelBtn.addEventListener('click', resetForm);

// Fetch notes on page load
fetchNotes();
