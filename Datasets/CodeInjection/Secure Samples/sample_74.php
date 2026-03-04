<?php
$loader = new \Twig\Loader\FilesystemLoader(__DIR__ . '/templates');
$twig = new \Twig\Environment($loader, ['autoescape' => 'html']);
echo $twig->render('hello.html', ['name' => ($_GET['name'] ?? 'Guest')]);
?>