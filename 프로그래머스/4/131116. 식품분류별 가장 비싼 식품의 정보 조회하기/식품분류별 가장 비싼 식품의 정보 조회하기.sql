select a.category as CATEGORY, a.price as MAX_PRICE, PRODUCT_NAME
from food_product a, 
(
    select CATEGORY, max(price) as MAX_PRICE
    from food_product
    group by category
    having category in ('과자','국','김치','식용유')
 ) as b
where a.price = b.max_price and a.category = b.category
order by price desc


# P0051	맛있는배추김치	CD_KC00001	김치	19000
# P0014	맛있는마조유	CD_OL00004	식용유	8950
# P0074	맛있는김치찌개	CD_SU00004	국	2900
# P0093	맛있는허니버터칩	CD_CK00003	과자	1950