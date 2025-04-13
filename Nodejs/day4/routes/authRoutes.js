const express = require('express');
const router = express.Router();

const { Register ,Login} = require('../controllers/authController');
const { vaildateLogin ,vaildateRegisteration} = require('../middleware/vaildation');
router.post('/register',vaildateRegisteration,Register);
router.post('/login',vaildateLogin, Login);
module.exports = router;