require 'sinatra'
post '/upload' do
  f=params[:file][:tempfile]
  name=params[:file][:filename]
  File.open("uploads/"+name,'wb'){|o| o.write(f.read)}
  'ok'
end