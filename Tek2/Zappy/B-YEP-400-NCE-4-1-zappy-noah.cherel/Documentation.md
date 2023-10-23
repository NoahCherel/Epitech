# Documentation:

## GUI-to-Server commands
- **`msz`**: This command returns the size of the map. The server will respond with `msz X Y` where X and Y are the width and height of the map, respectively.
- **`bct X Y`**: This command returns the content of a tile. The server will respond with `bct X Y q0 q1 q2 q3 q4 q5 q6` where X and Y are the coordinates of the tile, and q0 to q6 are the quantities of each resource on the tile.
- **`mct`**: This command returns the content of the entire map. The server will respond with `bct X Y q0 q1 q2 q3 q4 q5 q6` for each tile on the map.
- **`tna`**: This command returns the name of a team. The server will respond with `tna N` where N is the name of the team.
- **`ppo #n`**: This command returns the position and orientation of a player. The server will respond with `ppo #n X Y O` where #n is the player number, X and Y are the coordinates of the player, and O is the orientation of the player.
- **`plv #n`**: This command returns the level of a player. The server will respond with `plv #n L` where #n is the player number, and L is the level of the player.
- **`pin #n`**: This command returns the inventory of a player. The server will respond with `pin #n X Y q0 q1 q2 q3 q4 q5 q6` where #n is the player number, X and Y are the coordinates of the player, and q0 to q6 are the quantities of each resource in the player's inventory.
- **`sgt T`**: This command returns the time unit. The server will respond with sgt T where T is the time unit.
- **`sst T`**: This command sets the time unit. The server will respond with sst T where T is the time unit.

## Server-to-GUI commands
- **`pnw #n X Y O L N`**: This command notifies the client that a new player has connected.
- **`pex n`**: This command notifies the client that a player has been expelled.
- **`pbc n M`**: This command broadcasts a message to all players.
- **`pic X Y L n n ...`**: This command starts an incantation. X and Y are the coordinates of the player who started the incantation, L is the level of the incantation, and #n are the player numbers who are participating in the incantation.
- **`pie X Y R`**: This command ends an incantation. The server will respond with pie X Y R where X and Y are the coordinates of the player who started the incantation, and R is the result of the incantation.
- **`pfk n`**: This command notifies the client that a player has laid an egg. The server will respond with pfk #n where #n is the player number.
- **`pdr n i`**: This command drops a resource. The server will respond with pdr #n i where #n is the player number, and i is the resource number.
- **`pgt n i`**: This command collects a resource. The server will respond with pgt #n i where #n is the player number, and i is the resource number.
- **`pdi n`**: This command notifies the client that a player has died. The server will respond with pdi #n where #n is the player number.
- **`enw e n X Y`**: This command notifies the client that an egg has been laid. The server will respond with enw e #n X Y where e is the egg number, #n is the player number who laid the egg, and X and Y are the coordinates of the egg.
- **`ebo e`**: This command notifies the client that an egg has hatched. The server will respond with ebo e where e is the egg number.
- **`edi e`**: This command notifies the client that an egg has died. The server will respond with edi e where e is the egg number.
- **`seg N`**: This command ends the game. The server will respond with seg N where N is the name of the winning team.
- **`smg M`**: This command sends a message to the server. The server will respond with smg M where M is the message.
- **`suc`**: This command notifies the client that an unknown command has been received. The server will respond with suc.
- **`sbp`**: This command notifies the client that a command has been received with incorrect parameters. The server will respond with sbp.
