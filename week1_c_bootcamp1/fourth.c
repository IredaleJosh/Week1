    int a;
    printf("Enter an mark: ");
    scanf("%d", &a);
    if(a >= 40)
    {
        printf("The mark of %d is a pass\n", a);
    }
    else
    {
        printf("The mark of %d is a fail\n", a);
    }
    return 0;

    int a = 2;
    switch (a)
    {
        case 2: printf ("Option 0 has been selected\n");
        break; 

        case 0: printf ("Option 1 has been selected\n");
        break;

        default: printf ("A different option has been selected\n");
    }