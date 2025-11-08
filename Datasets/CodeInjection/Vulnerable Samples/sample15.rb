require 'erb'
tmpl = params[:template]
ERB.new(tmpl).result(binding)