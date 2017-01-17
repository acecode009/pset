
<?php
    //after deposit statement
    $row = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $balance = $row[0]["cash"];
    $sum =$_POST["amount"] ;
    echo"The Sum of $$sum was deposited into your account <br>";
    echo"Your balance is <strong>$$balance";
    echo json_decode('"\uD83D\uDE00"');
    
   
?>