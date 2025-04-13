const joi = require("joi");

const loginSchema = joi.object({
  email: joi.string().email().required(),
  password: joi
    .string()
    .min(6)
    .required()
    .pattern(new RegExp("^[a-zA-Z0-9]{6,30}$")),
});
const registerSchema = joi.object({
  name: joi.string().min(3).max(30).required(),
  email: joi.string().email().required(),
  password: joi
    .string()
    .min(6)
    .required()
    .pattern(new RegExp("^[a-zA-Z0-9]{6,30}$")),
  role: joi.string().valid("admin", "user").required(), 
});
const postSchema = joi.object({
  title: joi.string().min(3).max(100).required(),
  content: joi.string().min(10).required(),
  tags: joi.array().items(joi.string()).optional(),
  author: joi.string().required(),
})
const vaildateLogin = (req, res, next) => {
  const { error } = loginSchema.validate(req.body);
  if (error) {
    return next(res.json({ error: error.details[0].message }));
  }
  next();
};
const vaildateRegisteration = (req, res, next) => {
  const { error } = registerSchema.validate(req.body);
  if (error) {
    return next(res.json({ error: error.details[0].message }));
  }
  next();
};

const vaildatePost = (req, res, next) => {
  const { error } = postSchema.validate(req.body);
  if (error) {
    return next(res.json({ error: error.details[0].message }));
  }
  next();
};
module.exports = { vaildateLogin, vaildateRegisteration,vaildatePost };
