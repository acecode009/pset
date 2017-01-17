<table class = "table table-responsive table-hover">
  <thead>
    <tr>
      <th>Transaction</th>
      <th>Date</th>
      <th>Symbol</th>
      <th>Shares</th>
      <th>Price</th>
  </tr>
  </thead>
  <tbody>
     <?php foreach ($positions as $position): ?>

      <tr>
          
          <td class="red"><?=$position["transaction"]?></td> 
          <td><?= date("d/m/y, g:i A",strtotime($position["time"])) ?></td>
          <td><?= strtoupper($position["symbol"]) ?></td>
          <td><?= $position["shares"] ?></td>
          <td><?= "$". number_format($position["price"],2) ?></td>
      </tr>
      
    <?php endforeach ?>
    
   
  </tbody>
 
</table>

 
