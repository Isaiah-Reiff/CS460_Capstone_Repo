<?php
use Twig\Environment;
use Twig\Loader\ArrayLoader;
use Twig\Extension\SandboxExtension;
use Twig\Sandbox\SecurityPolicy;

// Strict policy: allow only variable interpolation
$policy = new SecurityPolicy(
    /* allowed tags    */ ['if'],
    /* allowed filters */ [],
    /* allowed methods */ [],
    /* allowed props   */ [],
    /* allowed funcs   */ []
);

$loader = new ArrayLoader([]);

// Enable sandbox mode
$twig = new Environment($loader);
$twig->addExtension(new SandboxExtension($policy, true));

// Only allow a fixed set of trusted templates
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