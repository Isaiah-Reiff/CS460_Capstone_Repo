const express=require('express');const multer=require('multer');const upload=multer({dest:'tmp/'});
const app=express();
app.post('/upload',upload.single('file'),(req,res)=>{const fs=require('fs');fs.renameSync(req.file.path,'uploads/'+req.file.originalname);res.send('ok');});