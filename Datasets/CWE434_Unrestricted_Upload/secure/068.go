package main
import (
 "io"
 "net/http"
 "os"
 "path/filepath"
 "github.com/google/uuid"
)
func upload(w http.ResponseWriter,r *http.Request){r.ParseMultipartForm(10<<20);f,fh,_:=r.FormFile("file");defer f.Close();ext:=filepath.Ext(fh.Filename);if(ext==".png"||ext==".jpg"||ext==".jpeg"){out, _ := os.Create(filepath.Join("uploads",uuid.New().String()+ext));defer out.Close();io.Copy(out,f);w.Write([]byte("ok"))}else{w.Write([]byte("bad"))}}
func main(){http.HandleFunc("/upload",upload);http.ListenAndServe(":8080",nil)}