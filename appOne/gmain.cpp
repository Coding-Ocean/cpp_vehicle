#include"libOne.h"
#include"shape.h"
#include"VEHICLE.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();

    float cx = width / 2;
    float cy = height / 2;
    
    VEHICLE vehicle;
    vehicle.setPos(cx,cy);
    vehicle.setScale(20);

    while (notQuit) {
        clear(60);
        VECTOR2 mouse(mouseX, mouseY);

        vehicle.setMaxSpeed(15);
        vehicle.setMaxForce(1.5f);
        VECTOR2 arrive = vehicle.arrive(mouse);
        //VECTOR2 arrive = vehicle.attracted(mouse);

        vehicle.setMaxForce(3.0f);
        VECTOR2 flee = vehicle.flee(mouse);

        vehicle.applyForce(arrive);
        if (isPress(MOUSE_LBUTTON)) {
            vehicle.applyForce(flee);
        }
        vehicle.update();

        //draw
        textSize(50);
        fill(255, 200, 0);
        circle(mouse.x, mouse.y, 60);
        fill(0);
        text("“÷", mouse.x - 25, mouse.y + 25);

        vehicle.draw();
    }
}
