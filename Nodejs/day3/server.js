const express = require("express");
const mongoose = require("mongoose");
const morgan = require("morgan");

const app = express();
const port = 4000;
const postRoutes = require("./routes/postRoutes");

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(morgan("dev"));

app.use("/posts", postRoutes);

mongoose
  .connect("mongodb://127.0.0.1:27017/posts")
  .then(() => {
    console.log("connected to db successfully");
  })
  .catch((err) => {
    console.error("error connecting to database");
    process.exit(1);
  });

app.listen(port, () => {
  console.log(`Server listen on port ${port}`);
});
