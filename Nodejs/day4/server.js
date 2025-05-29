const express = require("express");
const mongoose = require("mongoose");
const morgan = require("morgan");
const { aurhorizeAdmin, verifiedUser } = require("./middleware/auth");

const app = express();
const port = 3000;
const postRoutes = require("./routes/postRoutes");
const userRoutes = require("./routes/userRoutes");
const authRoutes = require("./routes/authRoutes");

require("dotenv").config();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.use(morgan("dev"));

app.use("/posts", postRoutes);
app.use("/users", userRoutes);
app.use("/api/auth", authRoutes);

// Protect the /admin route
app.use("/admin",  userRoutes);

console.log("mongo url", process.env.MONGO_URL);
mongoose
  .connect(process.env.MONGO_URL)
  .then(() => {
    console.log("connected to db successfully");
  })
  .catch((err) => {
    console.error("❌ Error connecting to database:", err.message);
    process.exit(1);
  });

app.listen(port, () => {
  console.log(`Server listen on port ${port}`);
});
