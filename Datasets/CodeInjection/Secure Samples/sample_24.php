<?php
$template = $_GET['tpl'] ?? "";

function render_template($template, $context = []) {
    return preg_replace_callback('/\{\{(.+?)\}\}/', function($matches) use ($context) {
        $key = trim($matches[1]);
        return isset($context[$key]) ? htmlspecialchars($context[$key], ENT_QUOTES, 'UTF-8') : '';
    }, $template);
}

$context = [
    'user' => 'Alice',
    'role' => 'admin'
];

echo render_template($template, $context);
?>