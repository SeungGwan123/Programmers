-- 코드를 입력하세요
SELECT b.title as TITLE, r.BOARD_ID, r.REPLY_ID, r.WRITER_ID, r.CONTENTS, date_format(r.CREATED_DATE,'%Y-%m-%d') as CREATED_DATE
from used_goods_board as b, used_GOODS_REPLY as r
where (DATE(b.created_date) >= '2022-10-01' and DATE(b.created_date) <='2022-10-31') 
and b.board_id = r.board_id
order by r.created_date asc, b.title asc