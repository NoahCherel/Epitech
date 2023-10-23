##
## EPITECH PROJECT, 2023
## B-YEP-400-NCE-4-1-zappy-noah.cherel
## File description:
## Player
##


class Elevation:
    def __init__(self):
        """Initialize an Elevation object.
        """
        self.nessessary_items = {
            "1": {
                "player": 1,
                "linemate": 1,
                "deraumere": 0,
                "sibur": 0,
                "mendiane": 0,
                "phiras": 0,
                "thystame": 0
            },
            "2": {
                "player": 2,
                "linemate": 1,
                "deraumere": 1,
                "sibur": 1,
                "mendiane": 0,
                "phiras": 0,
                "thystame": 0
            },
            "3": {
                "player": 2,
                "linemate": 2,
                "deraumere": 0,
                "sibur": 1,
                "mendiane": 0,
                "phiras": 2,
                "thystame": 0
            },
            "4": {
                "player": 4,
                "linemate": 1,
                "deraumere": 1,
                "sibur": 2,
                "mendiane": 0,
                "phiras": 1,
                "thystame": 0
            },
            "5": {
                "player": 4,
                "linemate": 1,
                "deraumere": 2,
                "sibur": 1,
                "mendiane": 3,
                "phiras": 0,
                "thystame": 0
            },
            "6": {
                "player": 6,
                "linemate": 1,
                "deraumere": 2,
                "sibur": 3,
                "mendiane": 0,
                "phiras": 1,
                "thystame": 0
            },
            "7": {
                "player": 6,
                "linemate": 2,
                "deraumere": 2,
                "sibur": 2,
                "mendiane": 2,
                "phiras": 2,
                "thystame": 1
            }
        }

    def check_elevation(self, player):
        """Check if the player can elevate.

        Args:
            player (Player): The player to check.

        Returns:
            str: - "0" if the player cannot elevate even if he drops all his items
                 - "1" if the player can elevate immediately
                 - the name of the item he needs to drop to elevate otherwise
        """
        vision_ressources = { # init the ressources on the tile only
                "player": 0,
                "linemate": 0,
                "deraumere": 0,
                "sibur": 0,
                "mendiane": 0,
                "phiras": 0,
                "thystame": 0
            }
        total_ressources = { # init the total ressources (on the tile + in the inventory)
                "player": 0,
                "linemate": 0,
                "deraumere": 0,
                "sibur": 0,
                "mendiane": 0,
                "phiras": 0,
                "thystame": 0
            }
        for item in player.inventory: # go through player's inventory
            if item in total_ressources:
                total_ressources[item] += player.inventory[item]
        for item in player.vision[0]: # go through dropped items
            if item in vision_ressources:
                vision_ressources[item] += 1
                total_ressources[item] += 1
        vision_need_more = False # are items on the tile not enough to elevate?
        vision_need_less = False # are there too many items on the tile?
        item_to_drop = ""
        item_to_take = ""
        for item in self.nessessary_items[str(player.level)]:
            if item in vision_ressources and vision_ressources[item] < self.nessessary_items[str(player.level)][item]:
                vision_need_more = True
                item_to_drop = item
                break
            if item in total_ressources and vision_ressources[item] > self.nessessary_items[str(player.level)][item]:
                vision_need_less = True
                item_to_take = item
                break
        if not vision_need_more and not vision_need_less:
            # print("items needed to elevate: ", self.nessessary_items[str(player.level)])
            # print("items on the tile: ", vision_ressources)
            return "1"
        item_to_find = ""
        for item in self.nessessary_items[str(player.level)]:
            if item in total_ressources and total_ressources[item] < self.nessessary_items[str(player.level)][item]:
                item_to_find = item
        if item_to_find != "" and item_to_find != "player":
            return "0"
        if item_to_take != "" and item_to_take != "player":
            return "Take " + item_to_take
        if item_to_drop != "" and item_to_drop != "player":
            return "Set " + item_to_drop
        if item_to_find == "player":
            return "Broadcast " + str(player.level)
        return "0"
