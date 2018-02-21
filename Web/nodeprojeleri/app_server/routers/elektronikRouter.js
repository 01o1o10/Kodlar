var express = require('express');
var router = express.Router();
var ctrl = require('../controllers/elektronikController');

router.get('/', ctrl.elektronik);
router.get('/bilgisayar', ctrl.bilgisayar);

module.exports = router;