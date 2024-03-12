SELECT o.ANIMAL_ID, o.NAME
FROM ANIMAL_OUTS as o
WHERE o.ANIMAL_ID not in (
    SELECT i.ANIMAL_ID
    FROM ANIMAL_INS as i
)
