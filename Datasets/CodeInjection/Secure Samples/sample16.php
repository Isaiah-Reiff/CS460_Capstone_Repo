<?php
$loader = new \Twig\Loader\FilesystemLoader('/templates');
$twig = new \Twig\Environment($loader, ['autoescape' => 'html']);
echo $twig->render('welcome.html', ['user' => 'Ann']);
?>
