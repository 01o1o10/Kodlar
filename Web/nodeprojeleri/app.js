var fs = require('fs');
var express = require('express');
var path = require('path');
var app = express();
var router = require('./app_server/routers/elektronikRouter');
app.use('/public', express.static(path.join(__dirname, 'public')));

app.use(function(req, res, next){
    console.log('Url: ' + req.url);
    console.log('Zaman: ' + Date.now());
    next();
});

app.use('/elektronik', router);

app.listen(8000);