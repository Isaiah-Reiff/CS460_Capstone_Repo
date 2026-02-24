String classBody = request.getParameter("classDef");
JavaCompiler compiler = ToolProvider.getSystemJavaCompiler();
compiler.run(null, null, null, "-sourcepath", classBody);