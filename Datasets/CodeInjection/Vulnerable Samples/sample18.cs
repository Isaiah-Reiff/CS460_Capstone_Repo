using Microsoft.CSharp;
string code = Request.Form["code"];
CSharpCodeProvider prov = new CSharpCodeProvider();
prov.CompileAssemblyFromSource(new CompilerParameters(), code);