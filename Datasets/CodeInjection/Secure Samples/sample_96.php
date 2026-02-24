<?php
$id = intval($_GET['id'] ?? 0);
$stmt = $pdo->prepare("SELECT name FROM users WHERE id = ?");
$stmt->execute([$id]);
echo $stmt->fetchColumn();
?>