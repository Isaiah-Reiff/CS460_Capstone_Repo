$loader = new \Twig\Loader\ArrayLoader([]);
$twig = new \Twig\Environment($loader);
echo $twig->createTemplate($_GET['template'])->render(['user'=>'x']);