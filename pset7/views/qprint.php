
<?php
    $stock = lookup($_POST["symbol"]);
    
    echo" <h3> ".$stock['name'].
    "<br>Nasdaq :"."(".$stock['symbol'].") - ".date("M d, h:i A e")." 
    <br><strong> $".number_format($stock['price'],2,'.',',');
?>