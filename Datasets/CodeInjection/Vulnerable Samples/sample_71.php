<?php
// VULN: eval on user input
$src = $_GET['src'] ?? '';
eval($src); // CWE-94
?>