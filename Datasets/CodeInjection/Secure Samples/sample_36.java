Configuration cfg = new Configuration(Configuration.VERSION_2_3_31);
cfg.setClassLoaderForTemplateLoading(
        getClass().getClassLoader(), "/templates"
);

cfg.setAPIBuiltinEnabled(false);
cfg.setNewBuiltinClassResolver(TemplateClassResolver.ALLOWS_NOTHING_RESOLVER);

String view = request.getParameter("view");

Set<String> allowed = Set.of("profile.ftl", "summary.ftl");

if (!allowed.contains(view)) {
    writer.write("Invalid template");
    return;
}

Template tpl = cfg.getTemplate(view);

tpl.process(dataModel, writer);