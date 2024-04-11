-- 코드를 작성해주세요
select count(time) as FISH_COUNT
from fish_info
where date_format(time,'%Y') = '2021'
