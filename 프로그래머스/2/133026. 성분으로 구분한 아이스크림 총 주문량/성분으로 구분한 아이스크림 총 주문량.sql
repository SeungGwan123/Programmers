-- 코드를 입력하세요
SELECT INGREDIENT_TYPE, sum(TOTAL_ORDER) as TOTAL_ORDER
from FIRST_HALF as f, ICECREAM_INFO as i
where f.flavor = i.flavor
group by INGREDIENT_TYPE
order by sum(TOTAL_ORDER) asc