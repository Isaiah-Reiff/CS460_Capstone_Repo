require 'sinatra'
require 'securerandom'
post '/upload' do
  fn=params[:file][:filename]
  ext=fn.split('.').last.downcase
  if ['png','jpg','jpeg'].include?(ext)
    name=SecureRandom.hex(8)+'.'+ext
    File.open('uploads/'+name,'wb'){|o| o.write(params[:file][:tempfile].read)}
    'ok'
  else
    'bad'
  end
end