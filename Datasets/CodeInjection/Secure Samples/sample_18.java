Configuration cfg = new Configuration(Configuration.VERSION_2_3_31);
cfg.setClassLoaderForTemplateLoading(
        getClass().getClassLoader(), "/templates"
);

// Optional: disable potentially dangerous features
cfg.setAPIBuiltinEnabled(false); // blocks access to ?api
cfg.setNewBuiltinClassResolver(TemplateClassResolver.ALLOWS_NOTHING_RESOLVER);

String view = request.getParameter("view");

// Whitelist of templates the user is allowed to select
Set<String> allowed = Set.of("profile.ftl", "summary.ftl");

if (!allowed.contains(view)) {
    writer.write("Invalid template");
    return;
}

Template tpl = cfg.getTemplate(view);

// Only data is user-controlled, not template code
tpl.process(dataModel, writer);