<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];
    $output = '';
    // TODO: search database for places matching $_GET["geo"], store in $places
    $places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name,admin_name1,admin_name2) AGAINST (?)", $_GET["geo"]);
   
   /* if(empty($places))
    {
        $output = "There was no search result";
    }
    else{
        while($row = mysql_fetch_array($places))
        {
            $postal_code = $row['postal_code'];
            $place_name = $row['place_name'];
            $admin_name1 = $row['admin_name1'];
            $admin_name2 = $row['admin_name2'];
            
            $output .= '<div>' .$postal_code. ' ' .$place_name. ' '.$admin_name1.' ' .$admin_name2. '</div>';
        }
    
    echo($output);
    foreach($q as $row)
    {
        array_push($places,$row);
    }*/
    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>