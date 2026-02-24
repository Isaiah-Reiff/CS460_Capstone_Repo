<?php
use Twig\Environment;
use Twig\Loader\ArrayLoader;
use Twig\Extension\SandboxExtension;
use Twig\Sandbox\SecurityPolicy;

$policy = new SecurityPolicy(
    /* allowed tags    */ ['if'],
    /* allowed filters */ [],
    /* allowed methods */ [],
    /* allowed props   */ [],
    /* allowed funcs   */ []
);

$loader = new ArrayLoader([]);

$twig = new Environment($loader);
$twig->addExtension(new SandboxExtension($policy, true));

$allowedTemplates = [
    'profile' => 'Hello {{ user }}!'
];

$templateName = $_GET['view'] ?? '';

if (array_key_exists($templateName, $allowedTemplates)) {
    echo $twig->render($allowedTemplates[$templateName], ['user' => 'x']);
} else {
    echo "Template not allowed.";
}
?>