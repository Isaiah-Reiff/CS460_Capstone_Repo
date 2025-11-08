using System.Threading.Tasks;
using Microsoft.CodeAnalysis.CSharp.Scripting;

public class Runner {
    public async Task<string> Execute(string userCode) {
        await CSharpScript.EvaluateAsync(userCode);
        return "executed";
    }
}
