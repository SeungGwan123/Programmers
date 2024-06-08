-- 코드를 입력하세요
with max_price as(
    select category, product_name, max(price) price
    from food_product
    where category in ('과자','국','김치','식용유')
    group by category
)

select m.category CATEGORY, m.price MAX_PRICE, fp.product_name PRODUCT_NAME
from max_price m, food_product fp
where m.category = fp.category and m.price = fp.price
order by m.price desc