const User = require("../models/User");

const getUserWithFullName = async (req, res) => {
  try {
    const user = await User.findById(req.params.id);
    if (!user) {
      return res.status(404).json({ error: "User Not Found" });
    }
    res.status(200).json({ name:user.name, fullName: user.fullName ,virtualFullName:user.fullName}); 
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};

const getUserWithPosts = async (req, res) => {
  try {
    const user = await User.findById(req.params.id).populate("posts");
    if (!user) {
      return res.status(404).json({ error: "User Not Found" });
    }
    res.status(200).json(user);
  } catch (err) {
    res.status(500).json({ error: err.message });
  }
};

module.exports = { getUserWithFullName, getUserWithPosts };
