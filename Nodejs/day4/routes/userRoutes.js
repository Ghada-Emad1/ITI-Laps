const express = require("express");
const router = express.Router();
const User = require("../models/User");
const {
  getUserWithFullName,
  getUserWithPosts,
} = require("../controllers/userController");

const { aurhorizeAdmin } = require("../middleware/auth");
const { verifiedUser } = require("../middleware/auth");
// create new user
router.post("/", async (req, res) => {
  try {
    const { name, email, password, role ,fullName} = req.body;
    const newUser = new User({ name, email, password, role,fullName });
    const savedUser = await newUser.save();
    res.status(200).json(savedUser);
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});
// get all users
router.get("/", async (req, res) => {
  try {
    const users = await User.find();
    res.json(users);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

//routes only for admin
router.get("/", verifiedUser, aurhorizeAdmin, async (req, res, next) => {
  try {
    const users = await User.find().select("-password");
    res.status(200).json(users);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// Route to get a user with their full name
router.get("/:id/fullname", getUserWithFullName);

// Route to get a user with their posts
router.get("/:id/posts", getUserWithPosts);

module.exports = router;
