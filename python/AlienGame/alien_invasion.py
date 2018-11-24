import pygame, sys
import game_function as gf
from settings import Settings
from ship import Ship
from pygame.sprite import Group

def run_game():
    pygame.init() # 初始化
    pygame.display.set_caption("Alien Invision") # 显示标题

    alien_settings = Settings() # 设置settings对象
    screen = pygame.display.set_mode((alien_settings.screen_width, alien_settings.screen_height)) # 从设置类中获取高度与宽度

    ship = Ship(screen, alien_settings) # ship对象
    bullets = Group() # 把所有子弹做成一个编组

    # 游戏开始主循环
    while True:
        gf.check_events(alien_settings, ship, screen, bullets) # 将事件监测抽象封装
        ship.update() # 更新坐标
        bullets.update() # 更新子弹
        gf.update_screen(alien_settings, screen, ship) # 将屏幕更新封装起来
"""
主函数
"""
if __name__ == '__main__':
    run_game()