package main
import (
 "io"
 "net/http"
 "os"
)
func upload(w http.ResponseWriter,r *http.Request){r.ParseMultipartForm(10<<20);f,fh,_:=r.FormFile("file");defer f.Close();out, _ := os.Create("uploads/"+fh.Filename);defer out.Close();io.Copy(out,f);w.Write([]byte("ok"))}
func main(){http.HandleFunc("/upload",upload);http.ListenAndServe(":8080",nil)}