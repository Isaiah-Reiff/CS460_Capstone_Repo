<?php
// VULN: user supplies template source
$twig = new \Twig\Environment(new \Twig\Loader\ArrayLoader([]));
$tpl = $_GET['tpl'] ?? 'Hello {{ name }}';
echo $twig->createTemplate($tpl)->render(['name' => 'Ann']); // CWE-94
?>