Configuration cfg = new Configuration(Configuration.VERSION_2_3_31);
Template t = new Template("user", request.getParameter("tpl"), cfg);
t.process(dataModel, writer);