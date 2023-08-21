# -- 코드를 입력하세요
SELECT ri.FOOD_TYPE, ri.REST_ID, ri.REST_NAME, ri.FAVORITES
from REST_INFO ri
where (food_type,favorites) in(select food_type, max(favorites) from rest_info r group by food_type)
group by ri.food_type
order by ri.food_type desc, ri.FAVORITES desc


# select * from rest_info order by food_type, favorites desc
#분 151 애플우스 8 
#양 102 따띠따띠뜨 3 
#일 230 스시사카우스 4
#중 20 만저 15
#한 734 은돼지 1