-- 코드를 입력하세요
SELECT i.animal_id ANIMAL_ID, i.animal_type ANIMAL_TYPE, i.name NAME
from animal_ins i, animal_outs o
where i.animal_id = o.animal_id and i.sex_upon_intake like ('Intact%') and (o.sex_upon_outcome like ('Spayed%') or o.sex_upon_outcome like ('Neutered%'))
order by animal_id