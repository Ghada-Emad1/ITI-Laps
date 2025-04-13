const jwt = require("jsonwebtoken");
const bcrpt = require("bcrypt");
const User = require("../models/User");

const Login = async (req, res, next) => {
  const {  email, password } = req.body;
  const user = await User.findOne({ email });
  if (!user) {
    return next(new Error("User Not Found", 404));
  }
  const matchedPassword = await bcrpt.compare(password, user.password);
  if (!matchedPassword) {
    return next(new Error("Password is Not Matched", 400));
  }
  const token = jwt.sign({ email: user.email }, process.env.JWT_SECRET);
  res.send({ status: "sucess", token });
};
const Register = async (req, res, next) => {
  const { name, email, password } = req.body;
  if (!name || !email || !password) {
    return next(new Error("Name , Email or Password Not Provide", 400));
  }
  try {
    const hashedPassword = await bcrpt.hash(password, 10);
    const user = await User.create({ name, email, password: hashedPassword });
    res.status(201).send(user);
  } catch (err) {
    next(err);
  }
};


module.exports = { Register,Login };
