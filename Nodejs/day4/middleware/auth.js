const jwt = require("jsonwebtoken");
const User = require("../models/User");
const Post = require("../models/Post");
const bcrpt = require("bcrypt");

const verifiedUser = async (req, res, next) => {
  const token = req.headers.authorization;
  if (!token) {
    return res.status(403).json({ error: "Token Not Found" });
  }
  try {
    const payload = jwt.verify(token, process.env.JWT_SECRET);
    if (!payload) {
      return res.status(403).json({ error: "Token Not Valid" });
    }
    const user = await User.findOne({ email: payload.email });
    if (!user) {
      return res.status(404).json({ error: "User Not Found" });
    }
    req.user = user; // Attach the user to the req object
    next();
  } catch (err) {
    return res.status(403).json({ error: "Invalid Token" });
  }
};

const aurhorizeAdmin = async (req, res, next) => { 
  const userRole = req.user.role;
  if (userRole !== "admin") {
    return res.status(403).json({ error: "Access Denied" });
  }
  next();
}

const restrictAuthorAndAdmin = async (req, res, next) => {
  if (!req.user) {
    return res.status(403).json({ error: "User Not Authenticated" });
  }

  const userRole = req.user.role;
  const postId = req.params.id;
  const userId = req.user._id;
  const post = await Post.findById(postId);
  if (!post) {
    return res.status(404).json({ error: "Post Not Found" });
  }
  const postAuthorId = post.author;
  if (userRole !== "admin" && userId.toString() !== postAuthorId.toString()) {
    return res.status(403).json({ error: "Access Denied" });
  }
  next();
};

module.exports= { verifiedUser,restrictAuthorAndAdmin,aurhorizeAdmin };