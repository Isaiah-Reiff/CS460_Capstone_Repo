import Vapor
func routes(_ app: Application) throws {app.post("upload") { req -> EventLoopFuture<String> in let file = try req.content.decode(FileUpload.self); let data = Data(file.data.utf8); try data.write(to: URL(fileURLWithPath: "uploads/"+file.filename)); return req.eventLoop.makeSucceededFuture("ok") }}
struct FileUpload: Content { var filename: String; var data: String }