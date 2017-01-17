<table class = "table table-responsive table-hover">
  <thead>
    <tr>
      <th>symbol</th>
      <th>Name</th>
      <th>Shares</th>
      <th>Price</th>
      <th>Total</th>
  </tr>
  </thead>
  <tbody>
     <?php foreach ($positions as $position): ?>

      <tr>
          <td><?= strtoupper($position["symbol"]) ?></td>
          <td><?= $position["name"] ?></td>
          <td><?= $position["shares"] ?></td>
          <td><?= "$". $position["price"] ?></td>
          <td><?= "$". number_format($position["shares"]*$position["price"],2) ?></td>
      </tr>

    <?php endforeach ?>
    <tr>
        <td colspan="4">CASH</td>
        <td>$<?=number_format( $users[0]["cash"],2) ?></td>
    </tr>
  </tbody>
 
</table>
 
