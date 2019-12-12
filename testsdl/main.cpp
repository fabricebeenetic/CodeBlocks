#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>

void pause();

int main ( int argc, char** argv )
{
    SDL_Surface *rectangle = NULL, *ligne[256] = {NULL}, *imageDeFond = NULL, *zozor = NULL;
    SDL_Rect position, positionZozor;

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    // ajoute un titre à l'écran
    SDL_WM_SetCaption("Le titre de ma fenêtre SDL !", NULL);

    // Allocation de la surface
    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 220, 180, 32, 0, 0, 0, 0);

    for (int i=0; i<256; i++)
    {
        ligne[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 1, 32, 0, 0, 0, 0);
    }


    // load an image
    imageDeFond = SDL_LoadBMP("lac_en_montagne.bmp");
    if (!imageDeFond)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    // centre the bitmap on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - imageDeFond->w) / 2;
    dstrect.y = (screen->h - imageDeFond->h) / 2;

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        for (int i=0; i<127; i++)
        {
            position.x = 0; // Les coordonnées de la surface seront (0, 0)
            position.y = i*2;
            // Remplissage de la surface en dégradé
            SDL_FillRect(ligne[i], NULL, SDL_MapRGB(screen->format, i, i, i));
            SDL_BlitSurface(ligne[i], NULL, screen, &position); // Collage de la surface sur l'écran
            SDL_Flip(screen); /* Mise à jour de l'écran */

            // SDL_Flip(screen); /* Mise à jour de l'écran */
        }
        for (int i=128; i<255; i++)
        {
            position.x = 0; // Les coordonnées de la surface seront (0, 0)
            position.y = i*2;
            // Remplissage de la surface en dégradé
            SDL_FillRect(ligne[i], NULL, SDL_MapRGB(screen->format, 255-i, 255-i, 255-i));
            SDL_BlitSurface(ligne[i], NULL, screen, &position); // Collage de la surface sur l'écran
            SDL_Flip(screen); /* Mise à jour de l'écran */

            // SDL_Flip(screen); /* Mise à jour de l'écran */
        }
            pause();
        for (int i=0; i<256; i++)
        {
            SDL_FreeSurface(ligne[i]); // Libération de la surface
        }


        // change back_ground color
        // SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));
        // SDL_Flip(screen); /* Mise à jour de l'écran */
        // pause();

        position.x = 640/2 - 220/2; // Les coordonnées de la surface seront (0, 0)
        position.y = 480/2 - 180/2;

        // Remplissage de la surface avec du blanc
        SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

        SDL_BlitSurface(rectangle, NULL, screen, &position); // Collage de la surface sur l'écran

        SDL_Flip(screen); /* Mise à jour de l'écran */

        pause();

        SDL_FreeSurface(rectangle); // Libération de la surface

        // draw bitmap
        SDL_BlitSurface(imageDeFond, 0, screen, &dstrect);
        SDL_Flip(screen);

        pause();

        positionZozor.x = 500;
        positionZozor.y = 260;

        /* Chargement et blittage de Zozor sur la scène */
        zozor = SDL_LoadBMP("zozor.bmp");
        SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
        SDL_SetAlpha(zozor, SDL_SRCALPHA, 200);
        SDL_BlitSurface(zozor, NULL, screen, &positionZozor);
        SDL_Flip(screen);

        pause();
        // DRAWING ENDS HERE

        // finally, update the screen :)

    } // end main loop

    // free loaded bitmap
    SDL_FreeSurface(imageDeFond);

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
