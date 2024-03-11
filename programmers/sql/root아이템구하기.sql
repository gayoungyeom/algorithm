SELECT info.ITEM_ID, info.ITEM_NAME
FROM ITEM_INFO as info JOIN ITEM_TREE as tree ON info.ITEM_ID = tree.ITEM_ID
WHERE tree.PARENT_ITEM_ID IS NULL
