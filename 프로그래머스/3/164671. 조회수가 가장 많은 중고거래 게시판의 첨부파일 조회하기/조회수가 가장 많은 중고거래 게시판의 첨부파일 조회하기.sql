-- 코드를 입력하세요
SELECT concat('/home/grep/src/', b.BOARD_ID, '/' , f.FILE_ID , f.FILE_NAME , f.FILE_EXT )as FILE_PATH 
from USED_GOODS_FILE as f , (select BOARD_ID, views from USED_GOODS_BOARD 
                             where views = (select max(views) from used_goods_board) ) as b
where f.BOARD_ID = b.BOARD_ID 
order by FILE_ID desc
