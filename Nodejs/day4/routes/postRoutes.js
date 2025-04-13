const express = require("express");
const router = express.Router();
const jwt = require("jsonwebtoken");
const Post = require("../models/Post");
const User = require("../models/User");

const { verifiedUser } = require("../middleware/auth");
const { restrictAuthorAndAdmin } = require("../middleware/auth");
const {vaildatePost} = require('../middleware/vaildation');
// create new post
router.post("/", verifiedUser,vaildatePost, async (req, res) => {
  try {
    const { title, content, tags,author } = req.body;
    const newPost = new Post({
      title,
      content,
      author: req.user.name,
      tags,
    });
    const savedPost = await newPost.save();
    res.status(200).json(savedPost);
  } catch (err) {
    res.status(400).json({ error: err.message });
  }
});
// get all posts
router.get("/", async (req, res) => {
  try {
    const posts = await Post.find().populate("author", "name");
    res.json(posts);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// get a single post by id
router.get("/:id", async (req, res) => {
  try {
    const post = await Post.findById(req.params.id);
    if (!post) {
      res.status(404).json({ message: "Post Not Found" });
    }
    res.json(post);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
//update a post by id
router.put("/:id", verifiedUser, restrictAuthorAndAdmin, async (req, res) => {
  try {
    const { title, content, tags } = req.body;
    const updatedPost = await Post.findByIdAndUpdate(
      req.params.id,
      { title, content, tags },
      { new: true, runValidators: true }
    );
    // console.log(updatedPost);
    if (!updatedPost) {
      res.status(404).json({ message: "Post Not Found" });
    }
    res.json(updatedPost);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

//delete a post
router.delete("/:id",verifiedUser, restrictAuthorAndAdmin, async (req, res) => {
  try {
    const deletedPost = await Post.findByIdAndDelete(req.params.id);
    //console.log(deletedPost);
    if (!deletedPost) {
      return res.status(404).json({ message: "Post Not Found" });
    }
    res.json({ message: "Post Deleted Successfully" });
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

//add comment to post
router.post("/:id/comments", async (req, res) => {
  try {
    const { text } = req.body;
    const post = await Post.findById(req.params.id);
    if (!post) {
      return res.status(404).json({ message: "Post Not Found" });
    }
    post.comments.push({ text });
    await post.save();
    res.status(201).json(post);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});

// like a post
router.post("/:id/like", async (req, res) => {
  try {
    const { userId } = req.body;
    const post = await Post.findById(req.params.id);
    if (!post) {
      return res.status(404).json({ message: "Post Not Found" });
    }
    const index = post.likes.indexOf(userId);
    if (index == -1) {
      post.likes.push(userId);
    } else {
      post.likes.splice(index, 1);
    }
    await post.save();
    res.json(post);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
});
module.exports = router;
