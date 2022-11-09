from robot_control_class import RobotControl

# class for turtlebot to define its motion


class mazesolver():
    def __init__(self):
        self.turtlerobot = RobotControl()
        self.mazeEscaped = False

    def solvemaze(self):
        while(self.mazeEscaped is False):
            laserlistA = self.turtlerobot.get_laser_full()

            if (laserlistA[0] > 3 and laserlistA[360] > 3 and laserlistA[718] > 3):
                # self.turtlerobot.stop_robot()
                break

            else:
                self.motion_forward()
                self.laserlook()

    def motion_forward(self):
        while(self.turtlerobot.get_laser(360) > 1.15):
            self.turtlerobot.move_straight()
            if(self.turtlerobot.get_laser(0) > 3 and self.turtlerobot.get_laser(718) > 3):
                self.turtlerobot.stop_robot()
                break

        self.turtlerobot.stop_robot()

    def laserlook(self):
        laserlistB = self.turtlerobot.get_laser_full()

        if(laserlistB[0] > 3 and laserlistB[718] > 3):
            return

        elif (laserlistB[719] > 2):
            self.turtlerobot.rotate(-92)

        elif (laserlistB[0] > 2):
            self.turtlerobot.rotate(77)

        else:
            self.turtlerobot.rotate(180)


# END OF MAZESOLVER CLASS
# Motions to solve
tbm1 = mazesolver()
tbm1.solvemaze()

# tbm1.motion_forward()
# tbm1.laserlook()
# tbm1.motion_forward()
# tbm1.laserlook()
# tbm1.motion_forward()